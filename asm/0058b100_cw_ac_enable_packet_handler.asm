; func cw_ac_enable_packet_handler @ 0x0058b100 size=0x5c
  58b100:	3c02007c 	lui	v0,0x7c
  58b104:	27bdffe0 	addiu	sp,sp,-32
  58b108:	8c425988 	lw	v0,22920(v0)
  58b10c:	14400007 	bnez	v0,0x58b12c
  58b110:	afbf001c 	sw	ra,28(sp)
  58b114:	3c020075 	lui	v0,0x75
  58b118:	8fbf001c 	lw	ra,28(sp)
  58b11c:	24030001 	li	v1,1
  58b120:	27bd0020 	addiu	sp,sp,32
  58b124:	03e00008 	jr	ra
  58b128:	ac43cf5c 	sw	v1,-12452(v0)
  58b12c:	0c16276a 	jal	0x589da8
  58b130:	00000000 	nop
  58b134:	5040fff8 	beqzl	v0,0x58b118
  58b138:	3c020075 	lui	v0,0x75
  58b13c:	3c04006e 	lui	a0,0x6e
  58b140:	3c05006e 	lui	a1,0x6e
  58b144:	2484eef8 	addiu	a0,a0,-4360
  58b148:	24a51010 	addiu	a1,a1,4112
  58b14c:	0c101b74 	jal	0x406dd0
  58b150:	2406014c 	li	a2,332
  58b154:	08162c46 	j	0x58b118
  58b158:	3c020075 	lui	v0,0x75
