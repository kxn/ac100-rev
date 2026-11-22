; func _sso_notify_auth_join @ 0x0043a920 size=0x40
  43a920:	27bdffe0 	addiu	sp,sp,-32
  43a924:	afb00018 	sw	s0,24(sp)
  43a928:	afbf001c 	sw	ra,28(sp)
  43a92c:	0c10ea24 	jal	0x43a890
  43a930:	00808021 	move	s0,a0
  43a934:	10400006 	beqz	v0,0x43a950
  43a938:	8fbf001c 	lw	ra,28(sp)
  43a93c:	24040001 	li	a0,1
  43a940:	260500a3 	addiu	a1,s0,163
  43a944:	0c10e924 	jal	0x43a490
  43a948:	26060058 	addiu	a2,s0,88
  43a94c:	8fbf001c 	lw	ra,28(sp)
  43a950:	00001021 	move	v0,zero
  43a954:	8fb00018 	lw	s0,24(sp)
  43a958:	03e00008 	jr	ra
  43a95c:	27bd0020 	addiu	sp,sp,32
