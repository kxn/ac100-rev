; func cw_packet_queue_proc_num_get @ 0x0059be34 size=0x18
  59be34:	10800003 	beqz	a0,0x59be44
  59be38:	00001021 	move	v0,zero
  59be3c:	8c82000c 	lw	v0,12(a0)
  59be40:	8c42000c 	lw	v0,12(v0)
  59be44:	03e00008 	jr	ra
  59be48:	00000000 	nop
  59be4c:	00000000 	nop
