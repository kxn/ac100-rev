; func cw_ac_disable_packet_handler @ 0x0058b15c size=0x58
  58b15c:	3c02007c 	lui	v0,0x7c
  58b160:	27bdffe0 	addiu	sp,sp,-32
  58b164:	8c425988 	lw	v0,22920(v0)
  58b168:	14400006 	bnez	v0,0x58b184
  58b16c:	afbf001c 	sw	ra,28(sp)
  58b170:	3c020075 	lui	v0,0x75
  58b174:	8fbf001c 	lw	ra,28(sp)
  58b178:	27bd0020 	addiu	sp,sp,32
  58b17c:	03e00008 	jr	ra
  58b180:	ac40cf5c 	sw	zero,-12452(v0)
  58b184:	0c16276a 	jal	0x589da8
  58b188:	00000000 	nop
  58b18c:	5040fff9 	beqzl	v0,0x58b174
  58b190:	3c020075 	lui	v0,0x75
  58b194:	3c04006e 	lui	a0,0x6e
  58b198:	3c05006e 	lui	a1,0x6e
  58b19c:	2484ef34 	addiu	a0,a0,-4300
  58b1a0:	24a50ff0 	addiu	a1,a1,4080
  58b1a4:	0c101b74 	jal	0x406dd0
  58b1a8:	24060145 	li	a2,325
  58b1ac:	08162c5d 	j	0x58b174
  58b1b0:	3c020075 	lui	v0,0x75
