; func _alarm_timeout @ 0x0043b0e0 size=0x24
  43b0e0:	27bdffe0 	addiu	sp,sp,-32
  43b0e4:	afb00018 	sw	s0,24(sp)
  43b0e8:	3c100076 	lui	s0,0x76
  43b0ec:	afbf001c 	sw	ra,28(sp)
  43b0f0:	0c101f7c 	jal	0x407df0
  43b0f4:	8e04a2e0 	lw	a0,-23840(s0)
  43b0f8:	24040001 	li	a0,1
  43b0fc:	0c101b78 	jal	0x406de0
  43b100:	ae00a2e0 	sw	zero,-23840(s0)
