; func cw_wtp_mac_type_free @ 0x00585920 size=0x3c
  585920:	27bdffe0 	addiu	sp,sp,-32
  585924:	afb00018 	sw	s0,24(sp)
  585928:	00808021 	move	s0,a0
  58592c:	afbf001c 	sw	ra,28(sp)
  585930:	8c840010 	lw	a0,16(a0)
  585934:	10800005 	beqz	a0,0x58594c
  585938:	8fbf001c 	lw	ra,28(sp)
  58593c:	0c101f7c 	jal	0x407df0
  585940:	00000000 	nop
  585944:	ae000010 	sw	zero,16(s0)
  585948:	8fbf001c 	lw	ra,28(sp)
  58594c:	00001021 	move	v0,zero
  585950:	8fb00018 	lw	s0,24(sp)
  585954:	03e00008 	jr	ra
  585958:	27bd0020 	addiu	sp,sp,32
