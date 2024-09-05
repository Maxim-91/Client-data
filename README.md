The program allows users to input client information, compare data to find matches, and save or load the data to/from a file.

## Features

- **Client Data Input**: Input client information including gender, name, age, height, weight, and preferred ranges for age, height, and weight for matching.
- **Data Matching**: The program matches clients based on age, height, and weight preferences and displays the matched pairs.
- **Data Storage**: Save client data to a text file or load existing data from a file for further use.

## Structure Overview

### `Tstud` Structure

The program uses the `Tstud` structure to store information about each client, including:

- `pol`: Gender
- `im`: Name
- `vo`: Age
- `r`: Height
- `ves`: Weight
- `vo1`, `vo2`: Age range preferences for matching
- `r1`, `r2`: Height range preferences for matching
- `ves1`, `ves2`: Weight range preferences for matching

Client data is stored in the `st[50]` array, which can hold up to 50 clients.

## How It Works

### 1. Adding Client Data

The `TForm1::Button1Click` method allows users to input client data through the interface. The data is saved into the `st[]` array and displayed in `Memo1`. The information includes gender, name, age, height, weight, and matching preferences (age, height, and weight ranges).

### 2. Client Data Matching

The `TForm1::Button2Click` method performs the matching of clients based on the following conditions:
- One client must be male, and the other female.
- The second client must fall within the first client's specified range of age, height, and weight, and vice versa.

Matched pairs are displayed in `Memo2`, and after a match, the client's `pol` field is set to "0" to mark them as matched.

### 3. Saving Data to a File

The `TForm1::Button3Click` method saves the current client data to a file called `"Spusok_klientiv.text"`. It writes all client details, including matching preferences, to the file.

### 4. Loading Data from a File

The `TForm1::Button4Click` method loads client data from the `"Spusok_klientiv.text"` file back into the program. It reads the information and displays it in `Memo1`.
