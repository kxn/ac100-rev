; func cw_priv_ap_config_checksum_free @ 0x005a46f8 size=0x3c
  5a46f8:	27bdffe0 	addiu	sp,sp,-32
  5a46fc:	afb00018 	sw	s0,24(sp)
  5a4700:	00808021 	move	s0,a0
  5a4704:	afbf001c 	sw	ra,28(sp)
  5a4708:	8c840010 	lw	a0,16(a0)
  5a470c:	10800005 	beqz	a0,0x5a4724
  5a4710:	8fbf001c 	lw	ra,28(sp)
  5a4714:	0c101f7c 	jal	0x407df0
  5a4718:	00000000 	nop
  5a471c:	ae000010 	sw	zero,16(s0)
  5a4720:	8fbf001c 	lw	ra,28(sp)
  5a4724:	00001021 	move	v0,zero
  5a4728:	8fb00018 	lw	s0,24(sp)
  5a472c:	03e00008 	jr	ra
  5a4730:	27bd0020 	addiu	sp,sp,32
