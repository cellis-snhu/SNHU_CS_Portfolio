#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb  4 21:46:19 2024

@author: christopherel_snhu
"""

from pymongo import MongoClient
from bson.objectid import ObjectId

# AnimalShelter creates a CRUD (Create/Read/Update/Delete) object that 
# connects to a MongoDB instance and allows for creation and management
# of MongoDB records or 'documents'
class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, USER, PASS):
        # Initializing the MongoClient. This helps to 
        # access the MongoDB databases and collections.
        # This is hard-wired to use the aac database, the 
        # animals collection, and the aac user.
        # Definitions of the connection string variables are
        # unique to the individual Apporto environment.
        #
        # You must edit the connection variables below to reflect
        # your own instance of MongoDB!
        #
        # Connection Variables
        #
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 31358
        DB = 'AAC'
        COL = 'animals'
        #
        # Initialize Connection
        #
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]
        print(f"Connection to MongoDB database '{DB}' and collection '{COL}' successful")

    # The create method takes a dictionary in the data parameter and inserts a
    # new document into the MongoDB database instance, or raises an exception
    # if no data is provided.
    def create(self, data):
        # try to insert a record with provided data, or return a ValueError
        # if no data is provided
        try:
            # check data parameter is not None and is not an empty dictionary
            if data is not None and bool(data):
                # insert the data into the class' configured collection
                self.collection.insert_one(data)  # data should be dictionary
                # return true for successful inserts
                return True
            else:
                # if data is None or Empty dictionary, raise an error
                raise ValueError("Nothing to save, because data parameter is empty")
        # catch any exceptions starting with the specified value error, followed
        # by generic exceptions
        except ValueError as vErr:
            print("A ValueError occurred: ", vErr)
            # return False for failed inserts
            return False
        except Exception as err:
            print("An exception occurred: ", err)
            # return False for failed inserts
            return False

    # The read method takes a query key/value pair and returns all the results
    # that match it in a list, otherwise returning an empty list
    def read(self, query):
        # attempt to query with the input parameter values and return a list
        # of matching query results, otherwise catch any errors and return an
        # empty list.
        try:
            if query is not None:  # Ensure query is not None and not an empty dictionary
                # use MongoD's find function to query for the provided key/value pair    
                result = self.collection.find(query)
                # return a list with the result data
                return list(result)


        # catch any exceptions
        except Exception as err:
            print("An exception occurred: ", err)
        # return an empty list if any exceptions are caught during the query
        return []
    
    # Update method takes a query key/value pair, and update_data params, searching for documents
    # by the key value pairs in the query param, and replacing the fields in update_data
    # with the input values in that param. The function then returns the number of records
    # that have been updated.
    def update(self, query, update_data):
        try:
            # check that query and update data are both valid and non-empty,
            # then attempt to query with the query data and update any records
            # using the update_data parameter inputs.
            if query and bool(query) and update_data and bool(update_data):
                # Execute the update operation on all documents matching query
                result = self.collection.update_many(query, {"$set": update_data})
                # return the number of modified documents
                return result.modified_count
        except Exception as err:
            print("An exception occurred: ", err)
        # if the loop does not run, return 0 updated records
        return 0
    
    # The delete function takes a query key/value pair, and deletes all of the records
    # that match that query. It returns the number of deleted records.
    def delete(self, query):
        try:
            # check that query is valid and non-empty. Then attempt to delete
            # all records that match the query value.
            if query and bool(query):
                # Execute the delete operation based on the query
                result = self.collection.delete_many(query)
                # Return the number of deleted documents
                return result.deleted_count
        # catch any exceptions
        except Exception as err:
            print("An exception occurred: ", err)
        # if the loop does not run, return 0 deleted records
        return 0