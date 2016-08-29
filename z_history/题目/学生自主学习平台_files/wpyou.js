// SubNavigation
$(function() {
	$(".navi li").hover(function(){
		$(this).find('ul:first').show("fast").css({visibility: "visible",display: "block"});
	},function(){
		$(this).find('ul:first').hide("fast").css({visibility: "hidden"});
	});
});
