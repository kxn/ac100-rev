; func arp_defend_str2upper @ 0x004768c0 size=0x48
  4768c0:	00801021 	move	v0,a0
  4768c4:	00852821 	addu	a1,a0,a1
  4768c8:	2404ffdf 	li	a0,-33
  4768cc:	24a5ffff 	addiu	a1,a1,-1
  4768d0:	00a2182b 	sltu	v1,a1,v0
  4768d4:	1460000a 	bnez	v1,0x476900
  4768d8:	00000000 	nop
  4768dc:	80a30000 	lb	v1,0(a1)
  4768e0:	2466ff9f 	addiu	a2,v1,-97
  4768e4:	30c600ff 	andi	a2,a2,0xff
  4768e8:	2cc6001a 	sltiu	a2,a2,26
  4768ec:	50c0fff8 	beqzl	a2,0x4768d0
  4768f0:	24a5ffff 	addiu	a1,a1,-1
  4768f4:	00641824 	and	v1,v1,a0
  4768f8:	0811da33 	j	0x4768cc
  4768fc:	a0a30000 	sb	v1,0(a1)
  476900:	03e00008 	jr	ra
  476904:	00000000 	nop
