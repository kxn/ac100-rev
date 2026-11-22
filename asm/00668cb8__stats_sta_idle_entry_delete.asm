; func _stats_sta_idle_entry_delete @ 0x00668cb8 size=0x30
  668cb8:	10800007 	beqz	a0,0x668cd8
  668cbc:	8ca30000 	lw	v1,0(a1)
  668cc0:	8c820040 	lw	v0,64(a0)
  668cc4:	10400004 	beqz	v0,0x668cd8
  668cc8:	00000000 	nop
  668ccc:	0062102b 	sltu	v0,v1,v0
  668cd0:	10400003 	beqz	v0,0x668ce0
  668cd4:	00000000 	nop
  668cd8:	03e00008 	jr	ra
  668cdc:	00000000 	nop
  668ce0:	0819a30a 	j	0x668c28
  668ce4:	00000000 	nop
