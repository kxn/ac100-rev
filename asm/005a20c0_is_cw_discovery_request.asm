; func is_cw_discovery_request @ 0x005a20c0 size=0x60
  5a20c0:	27bdffe0 	addiu	sp,sp,-32
  5a20c4:	1080000c 	beqz	a0,0x5a20f8
  5a20c8:	afbf001c 	sw	ra,28(sp)
  5a20cc:	90830000 	lbu	v1,0(a0)
  5a20d0:	10600004 	beqz	v1,0x5a20e4
  5a20d4:	00001021 	move	v0,zero
  5a20d8:	8fbf001c 	lw	ra,28(sp)
  5a20dc:	03e00008 	jr	ra
  5a20e0:	27bd0020 	addiu	sp,sp,32
  5a20e4:	0c1687c2 	jal	0x5a1f08
  5a20e8:	00000000 	nop
  5a20ec:	38420001 	xori	v0,v0,0x1
  5a20f0:	08168836 	j	0x5a20d8
  5a20f4:	2c420001 	sltiu	v0,v0,1
  5a20f8:	3c040069 	lui	a0,0x69
  5a20fc:	3c05006e 	lui	a1,0x6e
  5a2100:	3c07006e 	lui	a3,0x6e
  5a2104:	2484d3ac 	addiu	a0,a0,-11348
  5a2108:	24a5665c 	addiu	a1,a1,26204
  5a210c:	240603d2 	li	a2,978
  5a2110:	0c101b74 	jal	0x406dd0
  5a2114:	24e7608c 	addiu	a3,a3,24716
  5a2118:	08168836 	j	0x5a20d8
  5a211c:	00001021 	move	v0,zero
