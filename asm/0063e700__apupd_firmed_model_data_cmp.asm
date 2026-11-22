; func _apupd_firmed_model_data_cmp @ 0x0063e700 size=0x30
  63e700:	27bdffe0 	addiu	sp,sp,-32
  63e704:	00001021 	move	v0,zero
  63e708:	10800006 	beqz	a0,0x63e724
  63e70c:	afbf001c 	sw	ra,28(sp)
  63e710:	10a00005 	beqz	a1,0x63e728
  63e714:	8fbf001c 	lw	ra,28(sp)
  63e718:	0c101e4c 	jal	0x407930
  63e71c:	2406001c 	li	a2,28
  63e720:	2c420001 	sltiu	v0,v0,1
  63e724:	8fbf001c 	lw	ra,28(sp)
  63e728:	03e00008 	jr	ra
  63e72c:	27bd0020 	addiu	sp,sp,32
