; func uac_done @ 0x0040b2c0 size=0x50
  40b2c0:	27bdff60 	addiu	sp,sp,-160
  40b2c4:	00002821 	move	a1,zero
  40b2c8:	27a40018 	addiu	a0,sp,24
  40b2cc:	afbf009c 	sw	ra,156(sp)
  40b2d0:	0c101cf0 	jal	0x4073c0
  40b2d4:	24060080 	li	a2,128
  40b2d8:	0c101e08 	jal	0x407820
  40b2dc:	00000000 	nop
  40b2e0:	3c050067 	lui	a1,0x67
  40b2e4:	3c070067 	lui	a3,0x67
  40b2e8:	27a40018 	addiu	a0,sp,24
  40b2ec:	24a55510 	addiu	a1,a1,21776
  40b2f0:	24e75520 	addiu	a3,a3,21792
  40b2f4:	0c101ebc 	jal	0x407af0
  40b2f8:	00403021 	move	a2,v0
  40b2fc:	0c101d74 	jal	0x4075d0
  40b300:	27a40018 	addiu	a0,sp,24
  40b304:	8fbf009c 	lw	ra,156(sp)
  40b308:	03e00008 	jr	ra
  40b30c:	27bd00a0 	addiu	sp,sp,160
