; func update_params_report_time @ 0x004a2560 size=0x28
  4a2560:	27bdffe0 	addiu	sp,sp,-32
  4a2564:	afbf001c 	sw	ra,28(sp)
  4a2568:	0c101f9c 	jal	0x407e70
  4a256c:	00000000 	nop
  4a2570:	3c020076 	lui	v0,0x76
  4a2574:	8fbf001c 	lw	ra,28(sp)
  4a2578:	27bd0020 	addiu	sp,sp,32
  4a257c:	ac437af4 	sw	v1,31476(v0)
  4a2580:	03e00008 	jr	ra
  4a2584:	00001021 	move	v0,zero
