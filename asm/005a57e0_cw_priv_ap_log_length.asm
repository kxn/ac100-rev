; func cw_priv_ap_log_length @ 0x005a57e0 size=0x4c
  5a57e0:	10800010 	beqz	a0,0x5a5824
  5a57e4:	00001021 	move	v0,zero
  5a57e8:	8c830004 	lw	v1,4(a0)
  5a57ec:	1060000c 	beqz	v1,0x5a5820
  5a57f0:	24020002 	li	v0,2
  5a57f4:	94850000 	lhu	a1,0(a0)
  5a57f8:	00602021 	move	a0,v1
  5a57fc:	08169605 	j	0x5a5814
  5a5800:	00001821 	move	v1,zero
  5a5804:	24630001 	addiu	v1,v1,1
  5a5808:	24840008 	addiu	a0,a0,8
  5a580c:	24c60004 	addiu	a2,a2,4
  5a5810:	00461021 	addu	v0,v0,a2
  5a5814:	0065302a 	slt	a2,v1,a1
  5a5818:	54c0fffa 	bnezl	a2,0x5a5804
  5a581c:	94860002 	lhu	a2,2(a0)
  5a5820:	3042ffff 	andi	v0,v0,0xffff
  5a5824:	03e00008 	jr	ra
  5a5828:	00000000 	nop
