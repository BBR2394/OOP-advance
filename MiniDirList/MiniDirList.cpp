/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-11 14:45:47
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-18 00:00:04
*/


#include <fstream>
#include "MiniDirList.hpp"

MiniDirList::MiniDirList() : _fileList("Bonjour\n")
{
	std::cout << "MiniDirList created" << std::endl;
}

MiniDirList::~MiniDirList()
{

}

std::string read_(boost::asio::ip::tcp::socket & socket) {
	boost::asio::streambuf buf;
	boost::asio::read_until( socket, buf, "\n" );
	std::string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}
void send_(boost::asio::ip::tcp::socket & socket, const std::string& message) {
	const std::string msg = message + "\n";
	boost::asio::write( socket, boost::asio::buffer(message) );
}

int MiniDirList::listFile()
{
	std::cout << "in list file of MiniDirList" << std::endl;
	std::string final;
	boost::filesystem::path p(".");
	std::vector<boost::filesystem::directory_entry> v;

	if(boost::filesystem::is_directory(p)) {
		std::cout << p << " is a directory containing:\n";
        copy(boost::filesystem::directory_iterator(p), boost::filesystem::directory_iterator(), back_inserter(v));
        std::cout << p << " is a directory containing:\n";

        for ( std::vector<boost::filesystem::directory_entry>::const_iterator it = v.begin(); it != v.end();  ++ it )
        {
            std::cout << "\x1b[36m$>"<< (*it).path().string() << std::endl;
		_fileList.append((*it).path().string());
		}
	}
	std::cout << "size : " << _fileList.size() << std::endl;

}

int MiniDirList::run()
{
	boost::asio::io_service io_service;
	std::cout << "run the web server" << std::endl;
	int port = 2396;
	std::string answer = "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain; charset=utf-8\n\nHello World!";
	std::string answerS = "HTTP/1.1 200 OK\nContent-Length: 13\nContent-Type: text/plain; charset=utf-8\n\nHello World!";
	std::string answerBis = "HTTP/1.1 200 OK\nContent-Length: 79\nContent-Type: text/html; charset=utf-8\n<html>\n<h1>Zeitschaltuhr</h1>\n<body>\n<p>salut tout le monde :-)</p>\n</body>\n</html>";
	std::string answerThird = "HTTP/1.1 200 OK\nContent-Type: text/html\n<!DOCTYPE html>\n<html>\n<head>\n<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n<title>Bonjour !</title></head>\n<body>\nText\n</body></html>";
	std::string allFile = "";
	//169
	std::string headerHttp = "HTTP/1.1 200 OK\nContent-Length: 275\nContent-Type: text/html; charset=utf-8\n\n";
	std::string line;
	std::string finaleAnswer = "";
	std::string htmlAnswerPart = "";
	std::ifstream myfile ("indexTwo.html");
	if (myfile.is_open())
	{
	  while ( getline (myfile,line) )
	  {
	    allFile += line;
	    allFile += '\n';
	  }
	  myfile.close();
	}

//listen for new connection
	boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port ));
//socket creation 
	boost::asio::ip::tcp::socket socket_(io_service);
//waiting for connection
	acceptor_.accept(socket_);
//read operation
	std::string message = read_(socket_);
	std::cout << message << std::endl;

//write operation
	//send_(socket_, "Hello From Server!");
	std::cout << "size text :  " << allFile.size();
	finaleAnswer  = headerHttp;
	htmlAnswerPart += allFile;
	htmlAnswerPart += _fileList;
	htmlAnswerPart += "</body>\n</html>";
	std::cout << "\x1b[34m"<< htmlAnswerPart << std::endl;
	std::cout << "\x1b[35m"<< htmlAnswerPart.size() << std::endl;
	finaleAnswer += htmlAnswerPart;
	send_(socket_, finaleAnswer);
	std::cout << "Servent sent Hello message to Client!" << std::endl;

	return 0;
}