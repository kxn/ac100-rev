; func uac_lldp_global_config_show @ 0x004a4544 size=0x44
  4a4544:	3c020073 	lui	v0,0x73
  4a4548:	3c04006a 	lui	a0,0x6a
  4a454c:	27bdffe0 	addiu	sp,sp,-32
  4a4550:	80451888 	lb	a1,6280(v0)
  4a4554:	afbf001c 	sw	ra,28(sp)
  4a4558:	0c101b74 	jal	0x406dd0
  4a455c:	2484e408 	addiu	a0,a0,-7160
  4a4560:	3c020076 	lui	v0,0x76
  4a4564:	3c04006a 	lui	a0,0x6a
  4a4568:	80457b34 	lb	a1,31540(v0)
  4a456c:	0c101b74 	jal	0x406dd0
  4a4570:	2484e424 	addiu	a0,a0,-7132
  4a4574:	3c040070 	lui	a0,0x70
  4a4578:	8fbf001c 	lw	ra,28(sp)
  4a457c:	27bd0020 	addiu	sp,sp,32
  4a4580:	08101dd4 	j	0x407750
  4a4584:	2484191c 	addiu	a0,a0,6428
