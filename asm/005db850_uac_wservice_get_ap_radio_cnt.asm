; func uac_wservice_get_ap_radio_cnt @ 0x005db850 size=0x74
  5db850:	27bdffe0 	addiu	sp,sp,-32
  5db854:	afb00018 	sw	s0,24(sp)
  5db858:	afbf001c 	sw	ra,28(sp)
  5db85c:	0c1827fb 	jal	0x609fec
  5db860:	00000000 	nop
  5db864:	00408021 	move	s0,v0
  5db868:	2402ffff 	li	v0,-1
  5db86c:	12020006 	beq	s0,v0,0x5db888
  5db870:	3c020075 	lui	v0,0x75
  5db874:	8fbf001c 	lw	ra,28(sp)
  5db878:	02001021 	move	v0,s0
  5db87c:	8fb00018 	lw	s0,24(sp)
  5db880:	03e00008 	jr	ra
  5db884:	27bd0020 	addiu	sp,sp,32
  5db888:	8c42fe70 	lw	v0,-400(v0)
  5db88c:	1040fffa 	beqz	v0,0x5db878
  5db890:	8fbf001c 	lw	ra,28(sp)
  5db894:	0c16276a 	jal	0x589da8
  5db898:	00000000 	nop
  5db89c:	5040fff6 	beqzl	v0,0x5db878
  5db8a0:	8fbf001c 	lw	ra,28(sp)
  5db8a4:	3c04006f 	lui	a0,0x6f
  5db8a8:	3c05006f 	lui	a1,0x6f
  5db8ac:	24844a64 	addiu	a0,a0,19044
  5db8b0:	24a57038 	addiu	a1,a1,28728
  5db8b4:	0c101b74 	jal	0x406dd0
  5db8b8:	24061430 	li	a2,5168
  5db8bc:	08176e1e 	j	0x5db878
  5db8c0:	8fbf001c 	lw	ra,28(sp)
