; func sensor_di_db_bssid_nested_mem_free @ 0x004dd1b8 size=0x3c
  4dd1b8:	27bdffe0 	addiu	sp,sp,-32
  4dd1bc:	afb00018 	sw	s0,24(sp)
  4dd1c0:	00808021 	move	s0,a0
  4dd1c4:	10800007 	beqz	a0,0x4dd1e4
  4dd1c8:	afbf001c 	sw	ra,28(sp)
  4dd1cc:	8c8400f4 	lw	a0,244(a0)
  4dd1d0:	10800005 	beqz	a0,0x4dd1e8
  4dd1d4:	8fbf001c 	lw	ra,28(sp)
  4dd1d8:	0c101f7c 	jal	0x407df0
  4dd1dc:	00000000 	nop
  4dd1e0:	ae0000f4 	sw	zero,244(s0)
  4dd1e4:	8fbf001c 	lw	ra,28(sp)
  4dd1e8:	8fb00018 	lw	s0,24(sp)
  4dd1ec:	03e00008 	jr	ra
  4dd1f0:	27bd0020 	addiu	sp,sp,32
