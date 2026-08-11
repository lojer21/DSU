import nltk
import string
import spacy
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer

nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')
nltk.download('wordnet')

text = "The Quick Brown Fox jumped over the 3 lazy dogs!!"

# 1. Lowercasing
text_lower = text.lower()
print("Lowercased:", text_lower)

# 2. Punctuation removal
text_no_punct = text_lower.translate(str.maketrans('', '', string.punctuation))
print("Punctuation removed:", text_no_punct)

# 3. Tokenization
tokens = word_tokenize(text_no_punct)
print("Tokens:", tokens)

# Stop word removal
stop_words = set(stopwords.words('english'))
filtered_tokens = [word for word in tokens if word not in stop_words]
print("Without Stop words:", filtered_tokens)

# Stemming
stemmer = PorterStemmer()
stemmed_tokens = [stemmer.stem(word) for word in filtered_tokens]
print("Stemmed:", stemmed_tokens)

# Lemmatization
lemmatizer = WordNetLemmatizer()
lemmatized_tokens = [lemmatizer.lemmatize(word) for word in filtered_tokens]
print("Lemmatized:", lemmatized_tokens)

# Lemmatization using spaCy
nlp = spacy.load('en_core_web_sm')
doc = nlp(text)
lemmatized_tokens_spacy = [token.lemma_ for token in doc]
print("Lemmatized using spaCy:", lemmatized_tokens_spacy)
