; func _wportal_dm_framed_ip_key_func @ 0x0042c6f4 size=0x30
  42c6f4:	27bdffe0 	addiu	sp,sp,-32
  42c6f8:	afb00018 	sw	s0,24(sp)
  42c6fc:	afbf001c 	sw	ra,28(sp)
  42c700:	0c101ee4 	jal	0x407b90
  42c704:	00808021 	move	s0,a0
  42c708:	02002021 	move	a0,s0
  42c70c:	8fbf001c 	lw	ra,28(sp)
  42c710:	00003021 	move	a2,zero
  42c714:	8fb00018 	lw	s0,24(sp)
  42c718:	27bd0020 	addiu	sp,sp,32
  42c71c:	081020f4 	j	0x4083d0
  42c720:	00402821 	move	a1,v0
