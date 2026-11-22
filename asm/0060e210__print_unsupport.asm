; func _print_unsupport @ 0x0060e210 size=0x34
  60e210:	27bdffd8 	addiu	sp,sp,-40
  60e214:	00802821 	move	a1,a0
  60e218:	afbf0024 	sw	ra,36(sp)
  60e21c:	84860042 	lh	a2,66(a0)
  60e220:	84870044 	lh	a3,68(a0)
  60e224:	8c820048 	lw	v0,72(a0)
  60e228:	3c040070 	lui	a0,0x70
  60e22c:	24842dcc 	addiu	a0,a0,11724
  60e230:	0c101b74 	jal	0x406dd0
  60e234:	afa20010 	sw	v0,16(sp)
  60e238:	8fbf0024 	lw	ra,36(sp)
  60e23c:	03e00008 	jr	ra
  60e240:	27bd0028 	addiu	sp,sp,40
