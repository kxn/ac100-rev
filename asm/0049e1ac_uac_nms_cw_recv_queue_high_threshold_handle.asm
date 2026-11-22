; func uac_nms_cw_recv_queue_high_threshold_handle @ 0x0049e1ac size=0x28
  49e1ac:	27bdffe0 	addiu	sp,sp,-32
  49e1b0:	afbf001c 	sw	ra,28(sp)
  49e1b4:	0c127823 	jal	0x49e08c
  49e1b8:	00002021 	move	a0,zero
  49e1bc:	3c020076 	lui	v0,0x76
  49e1c0:	8fbf001c 	lw	ra,28(sp)
  49e1c4:	24030001 	li	v1,1
  49e1c8:	27bd0020 	addiu	sp,sp,32
  49e1cc:	03e00008 	jr	ra
  49e1d0:	ac43796c 	sw	v1,31084(v0)
