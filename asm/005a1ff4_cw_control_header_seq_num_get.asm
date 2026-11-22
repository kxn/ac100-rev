; func cw_control_header_seq_num_get @ 0x005a1ff4 size=0x5c
  5a1ff4:	27bdffe0 	addiu	sp,sp,-32
  5a1ff8:	afb00018 	sw	s0,24(sp)
  5a1ffc:	00808021 	move	s0,a0
  5a2000:	10800009 	beqz	a0,0x5a2028
  5a2004:	afbf001c 	sw	ra,28(sp)
  5a2008:	0c1685ef 	jal	0x5a17bc
  5a200c:	00000000 	nop
  5a2010:	02021021 	addu	v0,s0,v0
  5a2014:	90420004 	lbu	v0,4(v0)
  5a2018:	8fbf001c 	lw	ra,28(sp)
  5a201c:	8fb00018 	lw	s0,24(sp)
  5a2020:	03e00008 	jr	ra
  5a2024:	27bd0020 	addiu	sp,sp,32
  5a2028:	3c040069 	lui	a0,0x69
  5a202c:	3c05006e 	lui	a1,0x6e
  5a2030:	3c07006e 	lui	a3,0x6e
  5a2034:	2484d3ac 	addiu	a0,a0,-11348
  5a2038:	24a5661c 	addiu	a1,a1,26140
  5a203c:	240603ae 	li	a2,942
  5a2040:	0c101b74 	jal	0x406dd0
  5a2044:	24e7608c 	addiu	a3,a3,24716
  5a2048:	08168806 	j	0x5a2018
  5a204c:	00001021 	move	v0,zero
