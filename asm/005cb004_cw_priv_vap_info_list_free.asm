; func cw_priv_vap_info_list_free @ 0x005cb004 size=0x70
  5cb004:	27bdffe0 	addiu	sp,sp,-32
  5cb008:	afbf001c 	sw	ra,28(sp)
  5cb00c:	afb00018 	sw	s0,24(sp)
  5cb010:	8c840010 	lw	a0,16(a0)
  5cb014:	10800008 	beqz	a0,0x5cb038
  5cb018:	3c020075 	lui	v0,0x75
  5cb01c:	0c1729b1 	jal	0x5ca6c4
  5cb020:	00008021 	move	s0,zero
  5cb024:	8fbf001c 	lw	ra,28(sp)
  5cb028:	02001021 	move	v0,s0
  5cb02c:	8fb00018 	lw	s0,24(sp)
  5cb030:	03e00008 	jr	ra
  5cb034:	27bd0020 	addiu	sp,sp,32
  5cb038:	8c42cf58 	lw	v0,-12456(v0)
  5cb03c:	1040fff9 	beqz	v0,0x5cb024
  5cb040:	2410ffff 	li	s0,-1
  5cb044:	0c16276a 	jal	0x589da8
  5cb048:	00000000 	nop
  5cb04c:	5040fff6 	beqzl	v0,0x5cb028
  5cb050:	8fbf001c 	lw	ra,28(sp)
  5cb054:	3c04006d 	lui	a0,0x6d
  5cb058:	3c05006f 	lui	a1,0x6f
  5cb05c:	24847cb0 	addiu	a0,a0,31920
  5cb060:	24a51210 	addiu	a1,a1,4624
  5cb064:	0c101b74 	jal	0x406dd0
  5cb068:	24060198 	li	a2,408
  5cb06c:	08172c0a 	j	0x5cb028
  5cb070:	8fbf001c 	lw	ra,28(sp)
	...
