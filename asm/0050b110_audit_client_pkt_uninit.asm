; func audit_client_pkt_uninit @ 0x0050b110 size=0x68
  50b110:	3c060051 	lui	a2,0x51
  50b114:	27bdffe0 	addiu	sp,sp,-32
  50b118:	24040009 	li	a0,9
  50b11c:	24050050 	li	a1,80
  50b120:	afb00018 	sw	s0,24(sp)
  50b124:	afbf001c 	sw	ra,28(sp)
  50b128:	0c1666f8 	jal	0x599be0
  50b12c:	24c6aab8 	addiu	a2,a2,-21832
  50b130:	10400005 	beqz	v0,0x50b148
  50b134:	00408021 	move	s0,v0
  50b138:	3c020073 	lui	v0,0x73
  50b13c:	8c421b30 	lw	v0,6960(v0)
  50b140:	14400006 	bnez	v0,0x50b15c
  50b144:	3c04006c 	lui	a0,0x6c
  50b148:	8fbf001c 	lw	ra,28(sp)
  50b14c:	02001021 	move	v0,s0
  50b150:	8fb00018 	lw	s0,24(sp)
  50b154:	03e00008 	jr	ra
  50b158:	27bd0020 	addiu	sp,sp,32
  50b15c:	3c05006c 	lui	a1,0x6c
  50b160:	2484cacc 	addiu	a0,a0,-13620
  50b164:	24a5cc28 	addiu	a1,a1,-13272
  50b168:	0c101b74 	jal	0x406dd0
  50b16c:	24060166 	li	a2,358
  50b170:	08142c53 	j	0x50b14c
  50b174:	8fbf001c 	lw	ra,28(sp)
	...
