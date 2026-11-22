; func cw_80211_wtp_radio_configuration_free @ 0x0056bda8 size=0x3c
  56bda8:	27bdffe0 	addiu	sp,sp,-32
  56bdac:	afb00018 	sw	s0,24(sp)
  56bdb0:	00808021 	move	s0,a0
  56bdb4:	afbf001c 	sw	ra,28(sp)
  56bdb8:	8c840010 	lw	a0,16(a0)
  56bdbc:	10800005 	beqz	a0,0x56bdd4
  56bdc0:	8fbf001c 	lw	ra,28(sp)
  56bdc4:	0c101f7c 	jal	0x407df0
  56bdc8:	00000000 	nop
  56bdcc:	ae000010 	sw	zero,16(s0)
  56bdd0:	8fbf001c 	lw	ra,28(sp)
  56bdd4:	00001021 	move	v0,zero
  56bdd8:	8fb00018 	lw	s0,24(sp)
  56bddc:	03e00008 	jr	ra
  56bde0:	27bd0020 	addiu	sp,sp,32
