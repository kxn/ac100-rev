; func cw_initiate_download_free @ 0x005776f8 size=0x3c
  5776f8:	27bdffe0 	addiu	sp,sp,-32
  5776fc:	afb00018 	sw	s0,24(sp)
  577700:	00808021 	move	s0,a0
  577704:	afbf001c 	sw	ra,28(sp)
  577708:	8c840010 	lw	a0,16(a0)
  57770c:	10800005 	beqz	a0,0x577724
  577710:	8fbf001c 	lw	ra,28(sp)
  577714:	0c101f7c 	jal	0x407df0
  577718:	00000000 	nop
  57771c:	ae000010 	sw	zero,16(s0)
  577720:	8fbf001c 	lw	ra,28(sp)
  577724:	00001021 	move	v0,zero
  577728:	8fb00018 	lw	s0,24(sp)
  57772c:	03e00008 	jr	ra
  577730:	27bd0020 	addiu	sp,sp,32
