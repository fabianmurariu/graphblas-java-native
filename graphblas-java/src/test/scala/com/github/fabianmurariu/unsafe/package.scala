package com.github.fabianmurariu

import scala.collection.generic.CanBuildFrom
import scala.collection.mutable
import scala.language.higherKinds

package object unsafe {

  implicit class DistinctByDecorator[T, F[_] <: TraversableOnce[_]](val xs:F[T]) extends AnyVal {
   def distinctBy[A](f : T => A)(implicit CBF:CanBuildFrom[F[T], T, F[T]]):F[T] = {
     val xsf = xs.asInstanceOf[TraversableOnce[T]]
     val seen = mutable.HashSet.empty[A]
     val outBuilder = CBF()
     xsf.foreach[Unit]{t:T =>
       val a = f(t)
       if (!seen(a)){
         outBuilder += t
         seen += a
       }
     }
     outBuilder.result()
   }
  }

}
