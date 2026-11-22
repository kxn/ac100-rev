; func cw_sta_info_list_free @ 0x00580d68 size=0x4c
  580d68:	27bdffe0 	addiu	sp,sp,-32
  580d6c:	afb00018 	sw	s0,24(sp)
  580d70:	afbf001c 	sw	ra,28(sp)
  580d74:	8c820010 	lw	v0,16(a0)
  580d78:	10400009 	beqz	v0,0x580da0
  580d7c:	00808021 	move	s0,a0
  580d80:	8c44000c 	lw	a0,12(v0)
  580d84:	10800003 	beqz	a0,0x580d94
  580d88:	00000000 	nop
  580d8c:	0c101f7c 	jal	0x407df0
  580d90:	00000000 	nop
  580d94:	0c101f7c 	jal	0x407df0
  580d98:	8e040010 	lw	a0,16(s0)
  580d9c:	ae000010 	sw	zero,16(s0)
  580da0:	8fbf001c 	lw	ra,28(sp)
  580da4:	00001021 	move	v0,zero
  580da8:	8fb00018 	lw	s0,24(sp)
  580dac:	03e00008 	jr	ra
  580db0:	27bd0020 	addiu	sp,sp,32
