function FindProxyForURL(url,host)
{
	if (shExpMatch(host, "*.strongmailsystems.com"))
	{
		return "DIRECT";
	}
	else if(shExpMatch(host, "10.0.2.106") || shExpMatch(host, "ppud9090.persistent.co.in") || shExpMatch(host, "127.0.0.1") || shExpMatch(host, "*.selligent.com") || shExpMatch(host, "localhost"))
	{
		return "DIRECT";
	}
    else if(shExpMatch(host, "*.persistent.co.in") || shExpMatch(host, "*.persistent.com"))
    {
		return "PROXY 10.44.208.10:8080";
    }
	else if(shExpMatch(host, "*hotstar.com*")||shExpMatch(host, "*google-analytics.com*")||shExpMatch(host, "*drive.google.com*")||shExpMatch(host, "*espncricinfo.com*")|| shExpMatch(host, "*mail.google.com") || shExpMatch(host, "*googlevideo*") || shExpMatch(host, "*youtube.com*") || shExpMatch(host, "*youtu.be*") || shExpMatch(host, "*gaana.com*") || shExpMatch(host, "*dropbox.com") || shExpMatch(host, "*dropboxstatic.com") || shExpMatch(host,"*bollywoodlyrics.com") || shExpMatch(host, "*learningwhiledoing*") || shExpMatch(host, "*lyricsmasti*") || shExpMatch(host,"*ebay.in*") || shExpMatch(host, "*everesttech.net") || shExpMatch(host, "*ebay.com*") || shExpMatch(host, "*clipconverter.cc*") )
	{
		return "SOCKS5 localhost:5423";
	}
	else
	{
		return "PROXY 10.44.208.10:8080";
	}
}
