; func cw_msg_ele_priv_val_get_from_pkt @ 0x00583114 size=0x3c
  583114:	27bdffe0 	addiu	sp,sp,-32
  583118:	30a5ffff 	andi	a1,a1,0xffff
  58311c:	afb00018 	sw	s0,24(sp)
  583120:	00008021 	move	s0,zero
  583124:	10800005 	beqz	a0,0x58313c
  583128:	afbf001c 	sw	ra,28(sp)
  58312c:	0c160c1d 	jal	0x583074
  583130:	00000000 	nop
  583134:	54400001 	bnezl	v0,0x58313c
  583138:	8c500010 	lw	s0,16(v0)
  58313c:	8fbf001c 	lw	ra,28(sp)
  583140:	02001021 	move	v0,s0
  583144:	8fb00018 	lw	s0,24(sp)
  583148:	03e00008 	jr	ra
  58314c:	27bd0020 	addiu	sp,sp,32
