; func arp_defend_print_mem_stat @ 0x0047f0f4 size=0x3c
  47f0f4:	27bdffe0 	addiu	sp,sp,-32
  47f0f8:	afb00018 	sw	s0,24(sp)
  47f0fc:	3c100071 	lui	s0,0x71
  47f100:	afbf001c 	sw	ra,28(sp)
  47f104:	0c101dd4 	jal	0x407750
  47f108:	2604f394 	addiu	a0,s0,-3180
  47f10c:	3c040069 	lui	a0,0x69
  47f110:	00002821 	move	a1,zero
  47f114:	0c101b74 	jal	0x406dd0
  47f118:	24842fb8 	addiu	a0,a0,12216
  47f11c:	2604f394 	addiu	a0,s0,-3180
  47f120:	8fbf001c 	lw	ra,28(sp)
  47f124:	8fb00018 	lw	s0,24(sp)
  47f128:	08101dd4 	j	0x407750
  47f12c:	27bd0020 	addiu	sp,sp,32
