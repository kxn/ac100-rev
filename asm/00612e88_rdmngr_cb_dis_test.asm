; func rdmngr_cb_dis_test @ 0x00612e88 size=0x64
  612e88:	3c02007d 	lui	v0,0x7d
  612e8c:	27bdffe0 	addiu	sp,sp,-32
  612e90:	8c42c63c 	lw	v0,-14788(v0)
  612e94:	afb00018 	sw	s0,24(sp)
  612e98:	00808021 	move	s0,a0
  612e9c:	14400006 	bnez	v0,0x612eb8
  612ea0:	afbf001c 	sw	ra,28(sp)
  612ea4:	8fbf001c 	lw	ra,28(sp)
  612ea8:	00001021 	move	v0,zero
  612eac:	8fb00018 	lw	s0,24(sp)
  612eb0:	03e00008 	jr	ra
  612eb4:	27bd0020 	addiu	sp,sp,32
  612eb8:	0c16276a 	jal	0x589da8
  612ebc:	00000000 	nop
  612ec0:	5040fff9 	beqzl	v0,0x612ea8
  612ec4:	8fbf001c 	lw	ra,28(sp)
  612ec8:	3c040070 	lui	a0,0x70
  612ecc:	3c050070 	lui	a1,0x70
  612ed0:	24845434 	addiu	a0,a0,21556
  612ed4:	24a578a0 	addiu	a1,a1,30880
  612ed8:	24060ae1 	li	a2,2785
  612edc:	0c101b74 	jal	0x406dd0
  612ee0:	02003821 	move	a3,s0
  612ee4:	08184baa 	j	0x612ea8
  612ee8:	8fbf001c 	lw	ra,28(sp)
