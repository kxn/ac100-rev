; func sensor_di_db_destroy @ 0x004dd018 size=0x64
  4dd018:	3c020077 	lui	v0,0x77
  4dd01c:	27bdffe0 	addiu	sp,sp,-32
  4dd020:	8c4285f4 	lw	v0,-31244(v0)
  4dd024:	afbf001c 	sw	ra,28(sp)
  4dd028:	1440000c 	bnez	v0,0x4dd05c
  4dd02c:	afb00018 	sw	s0,24(sp)
  4dd030:	3c100077 	lui	s0,0x77
  4dd034:	8e0485fc 	lw	a0,-31236(s0)
  4dd038:	10800005 	beqz	a0,0x4dd050
  4dd03c:	8fbf001c 	lw	ra,28(sp)
  4dd040:	0c1020d8 	jal	0x408360
  4dd044:	00000000 	nop
  4dd048:	ae0085fc 	sw	zero,-31236(s0)
  4dd04c:	8fbf001c 	lw	ra,28(sp)
  4dd050:	8fb00018 	lw	s0,24(sp)
  4dd054:	03e00008 	jr	ra
  4dd058:	27bd0020 	addiu	sp,sp,32
  4dd05c:	3c04006b 	lui	a0,0x6b
  4dd060:	3c05006b 	lui	a1,0x6b
  4dd064:	2484d6ec 	addiu	a0,a0,-10516
  4dd068:	24a5f5cc 	addiu	a1,a1,-2612
  4dd06c:	0c101b74 	jal	0x406dd0
  4dd070:	24060723 	li	a2,1827
  4dd074:	0813740d 	j	0x4dd034
  4dd078:	3c100077 	lui	s0,0x77
