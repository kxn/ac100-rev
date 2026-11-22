; func is_cw_join_request @ 0x005a2120 size=0x60
  5a2120:	27bdffe0 	addiu	sp,sp,-32
  5a2124:	1080000c 	beqz	a0,0x5a2158
  5a2128:	afbf001c 	sw	ra,28(sp)
  5a212c:	90830000 	lbu	v1,0(a0)
  5a2130:	10600004 	beqz	v1,0x5a2144
  5a2134:	00001021 	move	v0,zero
  5a2138:	8fbf001c 	lw	ra,28(sp)
  5a213c:	03e00008 	jr	ra
  5a2140:	27bd0020 	addiu	sp,sp,32
  5a2144:	0c1687c2 	jal	0x5a1f08
  5a2148:	00000000 	nop
  5a214c:	38420003 	xori	v0,v0,0x3
  5a2150:	0816884e 	j	0x5a2138
  5a2154:	2c420001 	sltiu	v0,v0,1
  5a2158:	3c040069 	lui	a0,0x69
  5a215c:	3c05006e 	lui	a1,0x6e
  5a2160:	3c07006e 	lui	a3,0x6e
  5a2164:	2484d3ac 	addiu	a0,a0,-11348
  5a2168:	24a56674 	addiu	a1,a1,26228
  5a216c:	240603e6 	li	a2,998
  5a2170:	0c101b74 	jal	0x406dd0
  5a2174:	24e7608c 	addiu	a3,a3,24716
  5a2178:	0816884e 	j	0x5a2138
  5a217c:	00001021 	move	v0,zero
