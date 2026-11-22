; func _uac_rdmngr_pwr_level_cmp @ 0x006242ac size=0x9c
  6242ac:	27bdffd0 	addiu	sp,sp,-48
  6242b0:	24020001 	li	v0,1
  6242b4:	afb00024 	sw	s0,36(sp)
  6242b8:	00808021 	move	s0,a0
  6242bc:	afbf002c 	sw	ra,44(sp)
  6242c0:	00a02021 	move	a0,a1
  6242c4:	1200000d 	beqz	s0,0x6242fc
  6242c8:	afb10028 	sw	s1,40(sp)
  6242cc:	10a0000c 	beqz	a1,0x624300
  6242d0:	8fbf002c 	lw	ra,44(sp)
  6242d4:	0c101db4 	jal	0x4076d0
  6242d8:	00000000 	nop
  6242dc:	7c028c20 	seb	s1,v0
  6242e0:	3c02007d 	lui	v0,0x7d
  6242e4:	8c42c63c 	lw	v0,-14788(v0)
  6242e8:	14400009 	bnez	v0,0x624310
  6242ec:	00000000 	nop
  6242f0:	82020019 	lb	v0,25(s0)
  6242f4:	00518826 	xor	s1,v0,s1
  6242f8:	0011102b 	sltu	v0,zero,s1
  6242fc:	8fbf002c 	lw	ra,44(sp)
  624300:	8fb10028 	lw	s1,40(sp)
  624304:	8fb00024 	lw	s0,36(sp)
  624308:	03e00008 	jr	ra
  62430c:	27bd0030 	addiu	sp,sp,48
  624310:	0c16276a 	jal	0x589da8
  624314:	00000000 	nop
  624318:	5040fff6 	beqzl	v0,0x6242f4
  62431c:	82020019 	lb	v0,25(s0)
  624320:	3c040071 	lui	a0,0x71
  624324:	82070019 	lb	a3,25(s0)
  624328:	3c050071 	lui	a1,0x71
  62432c:	afb10010 	sw	s1,16(sp)
  624330:	2484afd8 	addiu	a0,a0,-20520
  624334:	24a5c8bc 	addiu	a1,a1,-14148
  624338:	0c101b74 	jal	0x406dd0
  62433c:	2406035f 	li	a2,863
  624340:	081890bd 	j	0x6242f4
  624344:	82020019 	lb	v0,25(s0)
