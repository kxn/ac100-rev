; func uac_wservice_pkt_uninit @ 0x005e8bcc size=0x7c
  5e8bcc:	3c06005e 	lui	a2,0x5e
  5e8bd0:	27bdffe0 	addiu	sp,sp,-32
  5e8bd4:	24040005 	li	a0,5
  5e8bd8:	24050064 	li	a1,100
  5e8bdc:	afb00018 	sw	s0,24(sp)
  5e8be0:	afbf001c 	sw	ra,28(sp)
  5e8be4:	0c1666f8 	jal	0x599be0
  5e8be8:	24c67d08 	addiu	a2,a2,32008
  5e8bec:	10400005 	beqz	v0,0x5e8c04
  5e8bf0:	00408021 	move	s0,v0
  5e8bf4:	3c020075 	lui	v0,0x75
  5e8bf8:	8c42fe70 	lw	v0,-400(v0)
  5e8bfc:	14400006 	bnez	v0,0x5e8c18
  5e8c00:	00000000 	nop
  5e8c04:	8fbf001c 	lw	ra,28(sp)
  5e8c08:	02001021 	move	v0,s0
  5e8c0c:	8fb00018 	lw	s0,24(sp)
  5e8c10:	03e00008 	jr	ra
  5e8c14:	27bd0020 	addiu	sp,sp,32
  5e8c18:	0c16276a 	jal	0x589da8
  5e8c1c:	00000000 	nop
  5e8c20:	5040fff9 	beqzl	v0,0x5e8c08
  5e8c24:	8fbf001c 	lw	ra,28(sp)
  5e8c28:	3c04006f 	lui	a0,0x6f
  5e8c2c:	3c05006f 	lui	a1,0x6f
  5e8c30:	24847944 	addiu	a0,a0,31044
  5e8c34:	24a57adc 	addiu	a1,a1,31452
  5e8c38:	0c101b74 	jal	0x406dd0
  5e8c3c:	240602c0 	li	a2,704
  5e8c40:	0817a302 	j	0x5e8c08
  5e8c44:	8fbf001c 	lw	ra,28(sp)
	...
