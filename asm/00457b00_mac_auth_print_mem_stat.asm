; func mac_auth_print_mem_stat @ 0x00457b00 size=0x40
  457b00:	27bdffe0 	addiu	sp,sp,-32
  457b04:	afb00018 	sw	s0,24(sp)
  457b08:	3c100071 	lui	s0,0x71
  457b0c:	afbf001c 	sw	ra,28(sp)
  457b10:	0c101dd4 	jal	0x407750
  457b14:	2604f394 	addiu	a0,s0,-3180
  457b18:	3c020076 	lui	v0,0x76
  457b1c:	3c040068 	lui	a0,0x68
  457b20:	8c457028 	lw	a1,28712(v0)
  457b24:	0c101b74 	jal	0x406dd0
  457b28:	24846e1c 	addiu	a0,a0,28188
  457b2c:	2604f394 	addiu	a0,s0,-3180
  457b30:	8fbf001c 	lw	ra,28(sp)
  457b34:	8fb00018 	lw	s0,24(sp)
  457b38:	08101dd4 	j	0x407750
  457b3c:	27bd0020 	addiu	sp,sp,32
