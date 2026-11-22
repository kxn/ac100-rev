; func MD5_Init @ 0x0051be78 size=0x3c
  51be78:	3c026745 	lui	v0,0x6745
  51be7c:	ac800004 	sw	zero,4(a0)
  51be80:	ac800000 	sw	zero,0(a0)
  51be84:	24422301 	addiu	v0,v0,8961
  51be88:	ac820008 	sw	v0,8(a0)
  51be8c:	3c02efcd 	lui	v0,0xefcd
  51be90:	3442ab89 	ori	v0,v0,0xab89
  51be94:	ac82000c 	sw	v0,12(a0)
  51be98:	3c0298ba 	lui	v0,0x98ba
  51be9c:	3442dcfe 	ori	v0,v0,0xdcfe
  51bea0:	ac820010 	sw	v0,16(a0)
  51bea4:	3c021032 	lui	v0,0x1032
  51bea8:	24425476 	addiu	v0,v0,21622
  51beac:	03e00008 	jr	ra
  51beb0:	ac820014 	sw	v0,20(a0)
