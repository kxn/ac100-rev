; func update_wstat_report_time @ 0x004a05d0 size=0x28
  4a05d0:	27bdffe0 	addiu	sp,sp,-32
  4a05d4:	afbf001c 	sw	ra,28(sp)
  4a05d8:	0c101f9c 	jal	0x407e70
  4a05dc:	00000000 	nop
  4a05e0:	3c020076 	lui	v0,0x76
  4a05e4:	8fbf001c 	lw	ra,28(sp)
  4a05e8:	27bd0020 	addiu	sp,sp,32
  4a05ec:	ac437a74 	sw	v1,31348(v0)
  4a05f0:	03e00008 	jr	ra
  4a05f4:	00001021 	move	v0,zero
