; func sensor_test_db_result_ret_nested_mem_free @ 0x005030f8 size=0x44
  5030f8:	27bdffe0 	addiu	sp,sp,-32
  5030fc:	afb00018 	sw	s0,24(sp)
  503100:	00808021 	move	s0,a0
  503104:	10800009 	beqz	a0,0x50312c
  503108:	afbf001c 	sw	ra,28(sp)
  50310c:	8c840064 	lw	a0,100(a0)
  503110:	10800007 	beqz	a0,0x503130
  503114:	8fbf001c 	lw	ra,28(sp)
  503118:	0c140a32 	jal	0x5028c8
  50311c:	00000000 	nop
  503120:	0c101f7c 	jal	0x407df0
  503124:	8e040064 	lw	a0,100(s0)
  503128:	ae000064 	sw	zero,100(s0)
  50312c:	8fbf001c 	lw	ra,28(sp)
  503130:	8fb00018 	lw	s0,24(sp)
  503134:	03e00008 	jr	ra
  503138:	27bd0020 	addiu	sp,sp,32
