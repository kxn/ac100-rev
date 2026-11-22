; func uac_wservice_pkt_init @ 0x005e8b50 size=0x7c
  5e8b50:	3c06005e 	lui	a2,0x5e
  5e8b54:	27bdffe0 	addiu	sp,sp,-32
  5e8b58:	24040005 	li	a0,5
  5e8b5c:	24050064 	li	a1,100
  5e8b60:	afb00018 	sw	s0,24(sp)
  5e8b64:	afbf001c 	sw	ra,28(sp)
  5e8b68:	0c16671e 	jal	0x599c78
  5e8b6c:	24c67d08 	addiu	a2,a2,32008
  5e8b70:	10400005 	beqz	v0,0x5e8b88
  5e8b74:	00408021 	move	s0,v0
  5e8b78:	3c020075 	lui	v0,0x75
  5e8b7c:	8c42fe70 	lw	v0,-400(v0)
  5e8b80:	14400006 	bnez	v0,0x5e8b9c
  5e8b84:	00000000 	nop
  5e8b88:	8fbf001c 	lw	ra,28(sp)
  5e8b8c:	02001021 	move	v0,s0
  5e8b90:	8fb00018 	lw	s0,24(sp)
  5e8b94:	03e00008 	jr	ra
  5e8b98:	27bd0020 	addiu	sp,sp,32
  5e8b9c:	0c16276a 	jal	0x589da8
  5e8ba0:	00000000 	nop
  5e8ba4:	5040fff9 	beqzl	v0,0x5e8b8c
  5e8ba8:	8fbf001c 	lw	ra,28(sp)
  5e8bac:	3c04006f 	lui	a0,0x6f
  5e8bb0:	3c05006f 	lui	a1,0x6f
  5e8bb4:	248478f0 	addiu	a0,a0,30960
  5e8bb8:	24a57ac4 	addiu	a1,a1,31428
  5e8bbc:	0c101b74 	jal	0x406dd0
  5e8bc0:	240602b3 	li	a2,691
  5e8bc4:	0817a2e3 	j	0x5e8b8c
  5e8bc8:	8fbf001c 	lw	ra,28(sp)
