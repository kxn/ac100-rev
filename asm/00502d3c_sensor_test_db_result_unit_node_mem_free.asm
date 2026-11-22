; func sensor_test_db_result_unit_node_mem_free @ 0x00502d3c size=0x58
  502d3c:	27bdffe0 	addiu	sp,sp,-32
  502d40:	afb00018 	sw	s0,24(sp)
  502d44:	00808021 	move	s0,a0
  502d48:	1080000e 	beqz	a0,0x502d84
  502d4c:	afbf001c 	sw	ra,28(sp)
  502d50:	8c840028 	lw	a0,40(a0)
  502d54:	50800007 	beqzl	a0,0x502d74
  502d58:	02002021 	move	a0,s0
  502d5c:	0c140a32 	jal	0x5028c8
  502d60:	00000000 	nop
  502d64:	0c101f7c 	jal	0x407df0
  502d68:	8e040028 	lw	a0,40(s0)
  502d6c:	ae000028 	sw	zero,40(s0)
  502d70:	02002021 	move	a0,s0
  502d74:	8fbf001c 	lw	ra,28(sp)
  502d78:	8fb00018 	lw	s0,24(sp)
  502d7c:	08101f7c 	j	0x407df0
  502d80:	27bd0020 	addiu	sp,sp,32
  502d84:	8fbf001c 	lw	ra,28(sp)
  502d88:	8fb00018 	lw	s0,24(sp)
  502d8c:	03e00008 	jr	ra
  502d90:	27bd0020 	addiu	sp,sp,32
