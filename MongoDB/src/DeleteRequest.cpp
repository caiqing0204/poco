//
// DeleteRequest.cpp
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  DeleteRequest
//
// Implementation of the DeleteRequest class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#include "Poco/MongoDB/DeleteRequest.h"
#include "Poco/MongoDB/BSONWriter.h"

namespace Poco
{
namespace MongoDB
{


DeleteRequest::DeleteRequest(const std::string& collectionName, DeleteRequest::Flags flags) 
	: RequestMessage(MessageHeader::Delete), 
	_flags(flags), 
	_fullCollectionName(collectionName),
	_selector()
{
}

DeleteRequest::~DeleteRequest()
{
}

void DeleteRequest::buildRequest(BinaryWriter& writer)
{
	BSONWriter bsonWriter(writer);
	writer << 0; // 0 - reserved for future use
	bsonWriter.writeCString(_fullCollectionName);
	writer << _flags;
	bsonWriter.write(_selector);
}


}} // Namespace MongoDB
