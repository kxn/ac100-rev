; func _uac_wsta_get_rd_freq_unit_name @ 0x00630708 size=0x3c
  630708:	27bdffe0 	addiu	sp,sp,-32
  63070c:	afbf001c 	sw	ra,28(sp)
  630710:	0c186b96 	jal	0x61ae58
  630714:	00000000 	nop
  630718:	0c18755b 	jal	0x61d56c
  63071c:	00402021 	move	a0,v0
  630720:	0c181fde 	jal	0x607f78
  630724:	00402021 	move	a0,v0
  630728:	50400004 	beqzl	v0,0x63073c
  63072c:	3c02006c 	lui	v0,0x6c
  630730:	8fbf001c 	lw	ra,28(sp)
  630734:	03e00008 	jr	ra
  630738:	27bd0020 	addiu	sp,sp,32
  63073c:	0818c1cc 	j	0x630730
  630740:	2442b290 	addiu	v0,v0,-19824
