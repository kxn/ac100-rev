; func cw_priv_ap_update_feature_free @ 0x005a9708 size=0x3c
  5a9708:	27bdffe0 	addiu	sp,sp,-32
  5a970c:	afb00018 	sw	s0,24(sp)
  5a9710:	00808021 	move	s0,a0
  5a9714:	afbf001c 	sw	ra,28(sp)
  5a9718:	8c840010 	lw	a0,16(a0)
  5a971c:	10800005 	beqz	a0,0x5a9734
  5a9720:	8fbf001c 	lw	ra,28(sp)
  5a9724:	0c101f7c 	jal	0x407df0
  5a9728:	00000000 	nop
  5a972c:	ae000010 	sw	zero,16(s0)
  5a9730:	8fbf001c 	lw	ra,28(sp)
  5a9734:	00001021 	move	v0,zero
  5a9738:	8fb00018 	lw	s0,24(sp)
  5a973c:	03e00008 	jr	ra
  5a9740:	27bd0020 	addiu	sp,sp,32
