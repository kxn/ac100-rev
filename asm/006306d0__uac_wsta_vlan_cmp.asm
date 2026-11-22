; func _uac_wsta_vlan_cmp @ 0x006306d0 size=0x38
  6306d0:	27bdffe0 	addiu	sp,sp,-32
  6306d4:	afb00018 	sw	s0,24(sp)
  6306d8:	00808021 	move	s0,a0
  6306dc:	afbf001c 	sw	ra,28(sp)
  6306e0:	0c101db4 	jal	0x4076d0
  6306e4:	00a02021 	move	a0,a1
  6306e8:	9603002e 	lhu	v1,46(s0)
  6306ec:	3042ffff 	andi	v0,v0,0xffff
  6306f0:	8fbf001c 	lw	ra,28(sp)
  6306f4:	8fb00018 	lw	s0,24(sp)
  6306f8:	27bd0020 	addiu	sp,sp,32
  6306fc:	00621826 	xor	v1,v1,v0
  630700:	03e00008 	jr	ra
  630704:	0003102b 	sltu	v0,zero,v1
