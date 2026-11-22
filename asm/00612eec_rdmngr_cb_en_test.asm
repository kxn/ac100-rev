; func rdmngr_cb_en_test @ 0x00612eec size=0x64
  612eec:	3c02007d 	lui	v0,0x7d
  612ef0:	27bdffe0 	addiu	sp,sp,-32
  612ef4:	8c42c63c 	lw	v0,-14788(v0)
  612ef8:	afb00018 	sw	s0,24(sp)
  612efc:	00808021 	move	s0,a0
  612f00:	14400006 	bnez	v0,0x612f1c
  612f04:	afbf001c 	sw	ra,28(sp)
  612f08:	8fbf001c 	lw	ra,28(sp)
  612f0c:	00001021 	move	v0,zero
  612f10:	8fb00018 	lw	s0,24(sp)
  612f14:	03e00008 	jr	ra
  612f18:	27bd0020 	addiu	sp,sp,32
  612f1c:	0c16276a 	jal	0x589da8
  612f20:	00000000 	nop
  612f24:	5040fff9 	beqzl	v0,0x612f0c
  612f28:	8fbf001c 	lw	ra,28(sp)
  612f2c:	3c040070 	lui	a0,0x70
  612f30:	3c050070 	lui	a1,0x70
  612f34:	24845470 	addiu	a0,a0,21616
  612f38:	24a5788c 	addiu	a1,a1,30860
  612f3c:	24060ada 	li	a2,2778
  612f40:	0c101b74 	jal	0x406dd0
  612f44:	02003821 	move	a3,s0
  612f48:	08184bc3 	j	0x612f0c
  612f4c:	8fbf001c 	lw	ra,28(sp)
