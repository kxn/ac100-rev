; func apmngr_check_evt_notify @ 0x0052ae68 size=0x1c8
  52ae68:	3c02007c 	lui	v0,0x7c
  52ae6c:	27bdffd0 	addiu	sp,sp,-48
  52ae70:	80425482 	lb	v0,21634(v0)
  52ae74:	afb20024 	sw	s2,36(sp)
  52ae78:	00809021 	move	s2,a0
  52ae7c:	afb10020 	sw	s1,32(sp)
  52ae80:	00a08821 	move	s1,a1
  52ae84:	afbf002c 	sw	ra,44(sp)
  52ae88:	afb30028 	sw	s3,40(sp)
  52ae8c:	1440003b 	bnez	v0,0x52af7c
  52ae90:	afb0001c 	sw	s0,28(sp)
  52ae94:	3c04007c 	lui	a0,0x7c
  52ae98:	24130001 	li	s3,1
  52ae9c:	0c10206c 	jal	0x4081b0
  52aea0:	24845804 	addiu	a0,a0,22532
  52aea4:	00408021 	move	s0,v0
  52aea8:	52000010 	beqzl	s0,0x52aeec
  52aeac:	24110001 	li	s1,1
  52aeb0:	16400016 	bnez	s2,0x52af0c
  52aeb4:	00000000 	nop
  52aeb8:	8e190014 	lw	t9,20(s0)
  52aebc:	13200005 	beqz	t9,0x52aed4
  52aec0:	00000000 	nop
  52aec4:	0320f809 	jalr	t9
  52aec8:	00000000 	nop
  52aecc:	1040004b 	beqz	v0,0x52affc
  52aed0:	3c02007c 	lui	v0,0x7c
  52aed4:	0c1021a0 	jal	0x408680
  52aed8:	02002021 	move	a0,s0
  52aedc:	00408021 	move	s0,v0
  52aee0:	1600fff3 	bnez	s0,0x52aeb0
  52aee4:	00000000 	nop
  52aee8:	24110001 	li	s1,1
  52aeec:	8fbf002c 	lw	ra,44(sp)
  52aef0:	02201021 	move	v0,s1
  52aef4:	8fb30028 	lw	s3,40(sp)
  52aef8:	8fb20024 	lw	s2,36(sp)
  52aefc:	8fb10020 	lw	s1,32(sp)
  52af00:	8fb0001c 	lw	s0,28(sp)
  52af04:	03e00008 	jr	ra
  52af08:	27bd0030 	addiu	sp,sp,48
  52af0c:	1653fff1 	bne	s2,s3,0x52aed4
  52af10:	00000000 	nop
  52af14:	8e190018 	lw	t9,24(s0)
  52af18:	1320ffee 	beqz	t9,0x52aed4
  52af1c:	00000000 	nop
  52af20:	12200027 	beqz	s1,0x52afc0
  52af24:	3c020075 	lui	v0,0x75
  52af28:	8e2502d8 	lw	a1,728(s1)
  52af2c:	0320f809 	jalr	t9
  52af30:	02202021 	move	a0,s1
  52af34:	1440ffe7 	bnez	v0,0x52aed4
  52af38:	3c02007c 	lui	v0,0x7c
  52af3c:	80425481 	lb	v0,21633(v0)
  52af40:	1040ffea 	beqz	v0,0x52aeec
  52af44:	00008821 	move	s1,zero
  52af48:	0c16276a 	jal	0x589da8
  52af4c:	00000000 	nop
  52af50:	5040ffe7 	beqzl	v0,0x52aef0
  52af54:	8fbf002c 	lw	ra,44(sp)
  52af58:	3c04006c 	lui	a0,0x6c
  52af5c:	3c05006c 	lui	a1,0x6c
  52af60:	248457cc 	addiu	a0,a0,22476
  52af64:	24a578c0 	addiu	a1,a1,30912
  52af68:	24060200 	li	a2,512
  52af6c:	0c101b74 	jal	0x406dd0
  52af70:	8e07000c 	lw	a3,12(s0)
  52af74:	0814abbc 	j	0x52aef0
  52af78:	8fbf002c 	lw	ra,44(sp)
  52af7c:	0c16276a 	jal	0x589da8
  52af80:	00000000 	nop
  52af84:	5040ffc4 	beqzl	v0,0x52ae98
  52af88:	3c04007c 	lui	a0,0x7c
  52af8c:	3c020075 	lui	v0,0x75
  52af90:	00121880 	sll	v1,s2,0x2
  52af94:	2442bea8 	addiu	v0,v0,-16728
  52af98:	3c04006c 	lui	a0,0x6c
  52af9c:	00621021 	addu	v0,v1,v0
  52afa0:	3c05006c 	lui	a1,0x6c
  52afa4:	24845730 	addiu	a0,a0,22320
  52afa8:	8c470000 	lw	a3,0(v0)
  52afac:	24a578c0 	addiu	a1,a1,30912
  52afb0:	0c101b74 	jal	0x406dd0
  52afb4:	240601e6 	li	a2,486
  52afb8:	0814aba6 	j	0x52ae98
  52afbc:	3c04007c 	lui	a0,0x7c
  52afc0:	8042bea4 	lb	v0,-16732(v0)
  52afc4:	1040ffca 	beqz	v0,0x52aef0
  52afc8:	8fbf002c 	lw	ra,44(sp)
  52afcc:	0c16276a 	jal	0x589da8
  52afd0:	00000000 	nop
  52afd4:	5040ffc6 	beqzl	v0,0x52aef0
  52afd8:	8fbf002c 	lw	ra,44(sp)
  52afdc:	3c04006c 	lui	a0,0x6c
  52afe0:	3c05006c 	lui	a1,0x6c
  52afe4:	2484579c 	addiu	a0,a0,22428
  52afe8:	24a578c0 	addiu	a1,a1,30912
  52afec:	0c101b74 	jal	0x406dd0
  52aff0:	240601fb 	li	a2,507
  52aff4:	0814abbc 	j	0x52aef0
  52aff8:	8fbf002c 	lw	ra,44(sp)
  52affc:	80425481 	lb	v0,21633(v0)
  52b000:	1040ffba 	beqz	v0,0x52aeec
  52b004:	00008821 	move	s1,zero
  52b008:	0c16276a 	jal	0x589da8
  52b00c:	00000000 	nop
  52b010:	5040ffb7 	beqzl	v0,0x52aef0
  52b014:	8fbf002c 	lw	ra,44(sp)
  52b018:	3c04006c 	lui	a0,0x6c
  52b01c:	3c05006c 	lui	a1,0x6c
  52b020:	24845760 	addiu	a0,a0,22368
  52b024:	24a578c0 	addiu	a1,a1,30912
  52b028:	0814abdb 	j	0x52af6c
  52b02c:	240601f1 	li	a2,497
