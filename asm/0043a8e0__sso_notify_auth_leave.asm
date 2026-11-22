; func _sso_notify_auth_leave @ 0x0043a8e0 size=0x40
  43a8e0:	27bdffe0 	addiu	sp,sp,-32
  43a8e4:	afb00018 	sw	s0,24(sp)
  43a8e8:	afbf001c 	sw	ra,28(sp)
  43a8ec:	0c10ea24 	jal	0x43a890
  43a8f0:	00808021 	move	s0,a0
  43a8f4:	10400006 	beqz	v0,0x43a910
  43a8f8:	8fbf001c 	lw	ra,28(sp)
  43a8fc:	00002021 	move	a0,zero
  43a900:	260500a3 	addiu	a1,s0,163
  43a904:	0c10e924 	jal	0x43a490
  43a908:	26060058 	addiu	a2,s0,88
  43a90c:	8fbf001c 	lw	ra,28(sp)
  43a910:	00001021 	move	v0,zero
  43a914:	8fb00018 	lw	s0,24(sp)
  43a918:	03e00008 	jr	ra
  43a91c:	27bd0020 	addiu	sp,sp,32
