; func wips_whitelist_update_with_scan_info @ 0x004c91b0 size=0x20
  4c91b0:	3c020073 	lui	v0,0x73
  4c91b4:	8c421aa0 	lw	v0,6816(v0)
  4c91b8:	14400003 	bnez	v0,0x4c91c8
  4c91bc:	3084ffff 	andi	a0,a0,0xffff
  4c91c0:	03e00008 	jr	ra
  4c91c4:	00001021 	move	v0,zero
  4c91c8:	08132384 	j	0x4c8e10
  4c91cc:	00000000 	nop
