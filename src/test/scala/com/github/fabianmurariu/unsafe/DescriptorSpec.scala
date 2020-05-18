package com.github.fabianmurariu.unsafe

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

trait DescriptorSpec {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Descriptor"
  it should "create a descriptor and get value back" in {
    val desc = GRBCORE.createDescriptor();
    GRBCORE.setDescriptorValue(desc, GRBCORE.GrB_OUTP, GRBCORE.GrB_REPLACE)
    GRBCORE.getDescriptorValue(desc, GRBCORE.GrB_OUTP) shouldBe GRBCORE.GrB_REPLACE

    GRBCORE.setDescriptorValue(desc, GRBCORE.GrB_INP0, GRBCORE.GrB_TRAN)
    GRBCORE.getDescriptorValue(desc, GRBCORE.GrB_INP0) shouldBe GRBCORE.GrB_TRAN
    GRBCORE.freeDescriptor(desc)
  }

  it should "keep the default value when the value doesn't match the field" in {
    val desc = GRBCORE.createDescriptor()
    GRBCORE.setDescriptorValue(desc, GRBCORE.GrB_OUTP, GRBCORE.GrB_TRAN)
    GRBCORE.getDescriptorValue(desc, GRBCORE.GrB_OUTP) shouldBe GRBCORE.GxB_DEFAULT
    GRBCORE.freeDescriptor(desc)
  }

}
