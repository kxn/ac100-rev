; func cw_priv_apdb_info_assemble @ 0x005ab390 size=0xb4
  5ab390:	27bdffd8 	addiu	sp,sp,-40
  5ab394:	afb1001c 	sw	s1,28(sp)
  5ab398:	00808821 	move	s1,a0
  5ab39c:	afb00018 	sw	s0,24(sp)
  5ab3a0:	00a08021 	move	s0,a1
  5ab3a4:	afbf0024 	sw	ra,36(sp)
  5ab3a8:	afb20020 	sw	s2,32(sp)
  5ab3ac:	8ca20010 	lw	v0,16(a1)
  5ab3b0:	94460000 	lhu	a2,0(v0)
  5ab3b4:	10c00006 	beqz	a2,0x5ab3d0
  5ab3b8:	94920004 	lhu	s2,4(a0)
  5ab3bc:	8c450004 	lw	a1,4(v0)
  5ab3c0:	10a00011 	beqz	a1,0x5ab408
  5ab3c4:	3c020075 	lui	v0,0x75
  5ab3c8:	0c15c856 	jal	0x572158
  5ab3cc:	00000000 	nop
  5ab3d0:	96220004 	lhu	v0,4(s1)
  5ab3d4:	00529023 	subu	s2,v0,s2
  5ab3d8:	9602000e 	lhu	v0,14(s0)
  5ab3dc:	02428026 	xor	s0,s2,v0
  5ab3e0:	2402ffff 	li	v0,-1
  5ab3e4:	0010100a 	movz	v0,zero,s0
  5ab3e8:	00408021 	move	s0,v0
  5ab3ec:	8fbf0024 	lw	ra,36(sp)
  5ab3f0:	02001021 	move	v0,s0
  5ab3f4:	8fb20020 	lw	s2,32(sp)
  5ab3f8:	8fb1001c 	lw	s1,28(sp)
  5ab3fc:	8fb00018 	lw	s0,24(sp)
  5ab400:	03e00008 	jr	ra
  5ab404:	27bd0028 	addiu	sp,sp,40
  5ab408:	8c42cf58 	lw	v0,-12456(v0)
  5ab40c:	1040fff7 	beqz	v0,0x5ab3ec
  5ab410:	2410ffff 	li	s0,-1
  5ab414:	0c16276a 	jal	0x589da8
  5ab418:	00000000 	nop
  5ab41c:	5040fff4 	beqzl	v0,0x5ab3f0
  5ab420:	8fbf0024 	lw	ra,36(sp)
  5ab424:	3c04006e 	lui	a0,0x6e
  5ab428:	3c05006f 	lui	a1,0x6f
  5ab42c:	248480d8 	addiu	a0,a0,-32552
  5ab430:	24a596ac 	addiu	a1,a1,-26964
  5ab434:	0c101b74 	jal	0x406dd0
  5ab438:	240600c6 	li	a2,198
  5ab43c:	0816acfc 	j	0x5ab3f0
  5ab440:	8fbf0024 	lw	ra,36(sp)
	...
