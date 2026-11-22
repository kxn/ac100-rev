; func update_event_report_time @ 0x004a12c0 size=0x28
  4a12c0:	27bdffe0 	addiu	sp,sp,-32
  4a12c4:	afbf001c 	sw	ra,28(sp)
  4a12c8:	0c101f9c 	jal	0x407e70
  4a12cc:	00000000 	nop
  4a12d0:	3c020076 	lui	v0,0x76
  4a12d4:	8fbf001c 	lw	ra,28(sp)
  4a12d8:	27bd0020 	addiu	sp,sp,32
  4a12dc:	ac437aa4 	sw	v1,31396(v0)
  4a12e0:	03e00008 	jr	ra
  4a12e4:	00001021 	move	v0,zero
